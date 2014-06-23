package diodevisualizer;

import com.jme3.material.Material;
import com.jme3.math.ColorRGBA;
import com.jme3.math.FastMath;
import com.jme3.math.Vector2f;
import com.jme3.scene.Geometry;
import com.jme3.scene.Node;
import com.jme3.scene.shape.*;

/**
 * Class containing informations about object to be displayed during a frame.
 * @author sliwhas
 */
public class VisibleObject {
    
    
    /** Object's number. */
    public int num;
    
    /** Object's position on scene. */
    public Vector2f position;
    
    /** Object's size. */
    public float size;
    
    /** Object's rotation. */
    public float rotation;
    
    /** Object's current speed. */
    public float speed;
    
    /** Objects' node. */
    private Node node;
    
    
    /**
     * Constructor.
     */
    public VisibleObject() {
        position = new Vector2f();
        size=rotation=speed=0;
        num = -1;
    }
    
    
    /**
     * Constructor.
     * @param num Object's number.
     * @param x X position on scene.
     * @param y Y position on scene.
     * @param size Size of the object.
     * @param rotation Object's rotation.
     * @param speed Object's current speed.
     */
    public VisibleObject(int num, float x, float y, float size, float rotation, float speed) {
        this.num = num;
        position = new Vector2f(x, y);
        this.size = size;
        this.rotation = rotation;
        this.speed = speed;
    }
    

    /**
     * Creates geometry for this object (if neccessary) and returns it.
     * @return the spatial
     */
    public Node getNode() {
        
        if (node!=null) return node;
        
        //Create node
        node = new Node();
        
        //Create box
        Box b = new Box(1, 0.2f, 2);
        Geometry bGeom = new Geometry("Box", b);
        bGeom.setMaterial(Main.assetManagerStatic.loadMaterial("MatDefs/Vehicle.j3m"));
        
        //Create sphere (front)
        Sphere s = new Sphere(20, 20, 0.5f);
        Geometry sGeom = new Geometry("Sphere", s);
        sGeom.move(0, 0.5f, 1);
        
        //Material for the sphere
        Material mat = new Material(Main.assetManagerStatic, "Common/MatDefs/Light/Lighting.j3md");
        mat.setColor("Diffuse", ColorRGBA.White);
        mat.setColor("Ambient", ColorRGBA.Gray);
        mat.setBoolean("UseMaterialColors", true);
        mat.setFloat("Shininess", 10);
        sGeom.setMaterial(mat);
        
        //Move, scale and rotate node
        node.move(position.x, 0, position.y);
        node.rotate(0, -(rotation/360f)*FastMath.TWO_PI, 0);
        node.scale(size);
        
        //Save and return
        node.attachChild(bGeom);
        node.attachChild(sGeom);
        return node;
    }
    
    
}
