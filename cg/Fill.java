/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;
import java.awt.*;
import static java.awt.Color.black;
import static java.awt.Color.red;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
/**
 *
 * @author kushal
 */
public class Fill extends JFrame {
    public void boundary(int x, int y, Color fill_color,Color boundary_color,Graphics g) 
{
    Robot r = null;
        try {
            r = new Robot();
        } catch (AWTException ex) {
            Logger.getLogger(Fill.class.getName()).log(Level.SEVERE, null, ex);
        }
    Color current;
    current = r.getPixelColor(x, y);
    if(current.getRGB() != boundary_color.getRGB() &&
       current.getRGB() != fill_color.getRGB())
    {
        g.setColor(Color.red);
        g.fillOval(x, y, 1, 1);
        boundary(x + 1, y, fill_color, boundary_color,g);
        boundary(x, y + 1, fill_color, boundary_color,g);
        boundary(x - 1, y, fill_color, boundary_color,g);
        boundary(x, y - 1, fill_color, boundary_color,g);
    }
}
     public void paint (Graphics g)
    {
        g.setColor(Color.black);
        g.drawRect(30, 70, 500, 40);
        boundary(40,40,red,black,g);
        
    }
     public static void main(String[] args) { 
        // TODO code application logic here 
        Fill obj = new Fill();
        obj.setTitle("Fill");
        obj.setSize(1366,768);
        obj.setVisible(true);
        
    }
}
