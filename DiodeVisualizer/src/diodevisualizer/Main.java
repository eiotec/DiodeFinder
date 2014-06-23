package diodevisualizer;

import com.jme3.app.SimpleApplication;
import com.jme3.asset.AssetManager;
import com.jme3.font.BitmapFont;
import com.jme3.font.BitmapText;
import com.jme3.light.AmbientLight;
import com.jme3.light.DirectionalLight;
import com.jme3.math.ColorRGBA;
import com.jme3.math.FastMath;
import com.jme3.math.Vector2f;
import com.jme3.math.Vector3f;
import com.jme3.scene.Geometry;
import com.jme3.scene.shape.Quad;
import com.jme3.system.AppSettings;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * test
 * @author normenhansen
 */
public class Main extends SimpleApplication {
    
    
    /** FIFO file with data. */
    public static FileInputStream fifo;
    
    /** Objects to be displayed. */
    List<VisibleObject> visibleObjects;
    
    /** Static assetsManager handler. */
    public static AssetManager assetManagerStatic;
    
    /** Whether the FIFO file is being read. */
    public boolean isReading;
    
    /** Recently read data. */
    private String lastData;
    
    /** GUI font. */
    private BitmapFont guiFont;
    
    

    /**
     * Main function.
     * @param args
     * @throws FileNotFoundException
     * @throws IOException 
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        //Open FIFO
        //fifo = new FileInputStream("/home/sliwhas/Documents/uczelnia/wizualizacja/test/data.fifo");
        class Waiter extends Thread {
            @Override
            public void run() {
                try {
                    fifo = new FileInputStream("data.fifo");
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        };
        (new Waiter()).start();
        
        //Configure settings
        AppSettings settings = new AppSettings(true);
        settings.setTitle("DiodeVisualizer");
        
        //Run the app
        Main app = new Main();
        app.setSettings(settings);
        app.setShowSettings(false);
        app.setDisplayFps(false);
        app.setDisplayStatView(false);
        app.start();
        
    }
    
    
    
    /**
     * Constructor.
     */
    public Main() {
        visibleObjects = new LinkedList<VisibleObject>();
        isReading = false;
    }

    
    
    /**
     * Performed during initialization.
     */
    @Override
    public void simpleInitApp() {
        
        //Make assetManager static
        Main.assetManagerStatic = getAssetManager();
        
        //Load font
        guiFont = assetManager.loadFont("Interface/Fonts/Default.fnt");
        
        //Configure vieport and camera
        flyCam.setMoveSpeed(10f);
        flyCam.setDragToRotate(true);
        cam.setLocation(new Vector3f(0, 6, 23));
        cam.lookAt(new Vector3f(6,0,6), Vector3f.UNIT_Y);
        viewPort.setBackgroundColor(new ColorRGBA(0.7f, 0.7f, 1f, 1f));
        
        //Add floor
        Quad q = new Quad(100, 100);
        q.scaleTextureCoordinates(new Vector2f(20, 20));
        Geometry fGeom = new Geometry("Floor", q);
        fGeom.setMaterial(assetManager.loadMaterial("MatDefs/Stone.j3m"));
        fGeom.rotate(-FastMath.HALF_PI, 0, 0);
        fGeom.setLocalTranslation(-q.getWidth()/2f, 0, q.getHeight()/2f);
        rootNode.attachChild(fGeom);
        
        //Ambient light
        AmbientLight alight = new AmbientLight();
        alight.setColor(ColorRGBA.White);
        rootNode.addLight(alight);
        
        //Directional light
        DirectionalLight light = new DirectionalLight();
        light.setColor(ColorRGBA.White);
        light.setDirection(new Vector3f(-1,1,-1));
        rootNode.addLight(light);
    }

    
    
    /**
     * Frame updating loop.
     * @param tpf Time per frame.
     */
    @Override
    public void simpleUpdate(float tpf) {
        
        updateStats();
        
        //Obtain data from FIFO.
        if (!isReading) {
            
            //Parse
            if (lastData!=null) {
                parseData(lastData);
                //updateStats();
                lastData = null;
            }
            
            //Read
            class Reader extends Thread {
                @Override
                public void run() {
                    isReading = true;
                    getData();
                    isReading = false;
                }
            };
            (new Reader()).start();
            
        }
        
    }
    
    
    
    /**
     * Get data from FIFO.
     */
    public void getData() {
        
        if (fifo==null) return;
        
        //Read from FIFO
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        byte[] data = new byte[4096];
        try {
            
            //Read and parse
            int num = fifo.read(data);
            baos.write(data);
            //System.out.println(baos.toString());
            lastData = baos.toString();
            
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    
    
    /**
     * Parsing data obtained from FIFO.
     * @param str String data.
     */
    public void parseData(String str) {
        
        //New visible objects
        List<VisibleObject> newVisibleObjects = new LinkedList<VisibleObject>();
        
        //Parse
        String[] arr = str.split("\\s");
        int len = arr.length;
        for (int i=0; i<len; i++) {
            
            //New frame
            if (arr[i].equals("F")) {
                
                //Skip next value
                i++;
                
            }
            
            //New object definition
            else if (arr[i].equals("D")) {
                
                //System.out.println("Nowy!");
                
                //Number
                i++;
                int num = Integer.parseInt(arr[i]);
                
                //Position
                i++;
                float x = Float.parseFloat(arr[i])/20f;
                i++;
                float y = Float.parseFloat(arr[i])/20f;
                
                //Size
                i++;
                float size = Float.parseFloat(arr[i])/100f;
                
                //Rotation
                i++;
                float rot = Float.parseFloat(arr[i]);
                
                //Speed
                i++;
                float speed = Float.parseFloat(arr[i]);
                
                //Add new object
                //System.out.println("D: "+num+", "+x+", "+y+", "+rot+", "+speed);
                VisibleObject obj = new VisibleObject(num, x, y, size, rot, speed);
                newVisibleObjects.add(obj);
                
            }
            
        }
        
        
        //Add all objects
        if (!newVisibleObjects.isEmpty()) {
            
            //Clear scene first
            //System.out.println("F clear!");
            clearScene();
            
            for (VisibleObject v : newVisibleObjects) {
                addObject(v);
            }
        }
        
    }
    
    
    
    /**
     * Updating statistics and infos.
     */
    public void updateStats() {
        
        if (!visibleObjects.isEmpty()) {
            
            //Detach all texts
            guiNode.detachAllChildren();
            
            //Now attach
            for (VisibleObject v : visibleObjects) {
                
                //Position
                BitmapText text1 = new BitmapText(guiFont);
                text1.setSize(guiFont.getCharSet().getRenderedSize());
                text1.setText("Position: "+Float.toString(v.position.x)+", "+Float.toString(v.position.y));
                text1.setLocalTranslation(cam.getScreenCoordinates(v.getNode().getWorldTranslation()).add(0, 100, 0));
                guiNode.attachChild(text1);
                
                //Rotation
                BitmapText text2 = new BitmapText(guiFont);
                text2.setSize(guiFont.getCharSet().getRenderedSize());
                text2.setText("Rotation: "+Float.toString(v.rotation));
                text2.setLocalTranslation(cam.getScreenCoordinates(v.getNode().getWorldTranslation()).add(0, 100-guiFont.getCharSet().getLineHeight(), 0));
                guiNode.attachChild(text2);
                
                //Speed
                BitmapText text3 = new BitmapText(guiFont);
                text3.setSize(guiFont.getCharSet().getRenderedSize());
                text3.setText("Speed: "+Float.toString(v.speed));
                text3.setLocalTranslation(cam.getScreenCoordinates(v.getNode().getWorldTranslation()).add(0, 100-2*guiFont.getCharSet().getLineHeight(), 0));
                guiNode.attachChild(text3);
                
            }
            
        }
        
    }
    
    
    
    /**
     * Adds a new visible object.
     * @param obj 
     */
    public void addObject(VisibleObject obj) {
        rootNode.attachChild(obj.getNode());
        visibleObjects.add(obj);
    }
    
    
    
    /**
     * Clears scene from all visible objects.
     */
    public void clearScene() {
        
        //Detach from root node
        for (VisibleObject v : visibleObjects) {
            rootNode.detachChild(v.getNode());
        }
        
        //Clear object list
        visibleObjects.clear();
        
    }
    
    
}
