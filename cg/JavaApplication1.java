/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;
import java.awt.*;
import javax.swing.JFrame;
import java.lang.*;
import java.util.*;



/**
 *
 * @author kushal
 */
public class JavaApplication1 extends JFrame {
    
    public void paint (Graphics g)
    {
//       dda(20, 20, 400, 400,g);
       bressen(80,80,200,80,g);
       g.setColor(Color.LIGHT_GRAY);
       dda(200,80,200,200,g);
       g.setColor(Color.BLUE);
       bressen(200,200,80,200,g);
       g.setColor(Color.GREEN);
       dda(80,200,80,80,g);
       g.setColor(Color.GREEN);
       
       dda(120,200,120,400,g);
       g.setColor(Color.cyan);
       dda(160,200,160,400,g);
       g.setColor(Color.cyan);
       
       dda(80,400,200,400,g);
       g.setColor(Color.RED);
       dda(200,400,200,520,g);
       g.setColor(Color.MAGENTA);
       dda(200,520,80,520,g);
       g.setColor(Color.ORANGE);
       dda(80,520,80,400,g);
      
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner cin = new Scanner(System.in);  
        JavaApplication1 obj = new JavaApplication1();
        obj.setTitle("hello");
        obj.setSize(700,800);
        obj.setVisible(true);
    }
    public void dda(int x1,int y1,int x2,int y2, Graphics g)
    {
        float len;
        int x,y;
        float dx = Math.abs((x2-x1));
        float dy = Math.abs((y2-y1));
        if(dx>=dy)
        {
            len = dx;
        }
        else
            len = dy;
        dx = (x2-x1)/len;
        dy = (y2-y1)/len;
        x = (int) (x1 + (0.5*Math.round(dx)));
        y = (int) (y1 + (0.5*Math.round(dy)));
        int i=1;
        while(i<len)
        {
            g.fillOval(x, y, 5, 5);
            x = (int) (x+dx);
            y = (int) (y+dy);
            i++;
        }
    }
    public int sign(int A)
    {
        if(A>0)
            return 1;
        else if (A==0)
            return 0;
        else
            return -1;
    }
    public void bressen(int x1,int y1,int x2,int y2, Graphics g)
    {
        float dx = Math.abs((x2-x1));
        float dy = Math.abs((y2-y1));
        int x=x1,y=y1;
        int s1,s2;
        s2= sign(y2-y1);
        s1= sign(x2-x1);
        boolean exc;
        if(dy>dx)
            exc=true;
        else
            exc=false;
        float e;
        e= (2*dy)-dx;
        int i=1;
        while(i<dx)
        {
        g.fillOval(x, y, 5, 5);
        while(e>=0)
        {
            if(exc==true)
                x=x+s1;
            else
                y=y+s2;
            
            
            e=e-2*dx;
            
        }
        if(exc == true)
            y=y+s2;
        else
            x=x+s1;
        e=e+2*dy;
        i++;
        }          
    }
    
}
