/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cgproj;
import java.awt.*;
import javax.swing.JFrame;
import java.lang.*;
import java.util.*;
/**
 *
 * @author kushal
 */
public class CGproj extends JFrame {
    public void paint (Graphics g)
    {
       g.setColor(Color.DARK_GRAY);
       dda(0,700,0,0,g);
       dda(0,700,200,700,g);
       dda(200,700,200,0,g);
       dda(200,0,0,0,g);
       dda(200,0,800,0,g);
       dda(800,0,800,700,g);
       dda(800,700,1000,700,g);
       dda(1000,700,1000,0,g);
       dda(1000,0,800,0,g);
       dda(250,0,250,700,g);
       dda(750,0,750,700,g);
       g.drawRect(490, 100, 20, 150);
       g.drawRect(490, 350, 20, 150);
       g.drawRect(490, 600, 20, 150);
       bresen_circle(100,100,25,g);
       bresen_circle(100,200,25,g);
       bresen_circle(100,300,25,g);
       bresen_circle(100,400,25,g);
       bresen_circle(100,500,25,g);
       bresen_circle(100,600,25,g);
       bresen_circle(900,100,25,g);
       bresen_circle(900,200,25,g);
       bresen_circle(900,300,25,g);
       bresen_circle(900,400,25,g);
       bresen_circle(900,500,25,g);
       bresen_circle(900,600,25,g);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        CGproj obj = new CGproj();
        obj.setTitle("hello");
        obj.setSize(1000,700);
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
    public void bresen_circle(int x1,int y1,int r,Graphics gl){
        float d = 3-2*r;
        int x=0,y=r;
        do{
        gl.fillOval(x1+x, y1+y, 3, 3);
        gl.fillOval(x1+x, y1-y, 3, 3);
        gl.fillOval(x1-x, y1+y, 3, 3);
        gl.fillOval(x1-x, y1-y, 3, 3);
        gl.fillOval(x1+y, y1+x, 3, 3);
        gl.fillOval(x1+y, y1-x, 3, 3);
        gl.fillOval(x1-y, y1+x, 3, 3);
        gl.fillOval(x1-y, y1-x, 3, 3);
         if(d<0)
            d=d+4*x+6;
        else{
            d= d+4*(x-y)+10;
            y=y-1;
        }
        x=x+1;
//        try 
//         {
//             Thread.sleep(15);
//         } 
//         catch(Throwable e) 
//         {
//         System.out.println(e.getMessage()); 
//         }
       }while(x<y);
     }
    
}
