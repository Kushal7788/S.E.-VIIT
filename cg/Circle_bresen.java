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
public class Circle_bresen extends JFrame {
         public void paint (Graphics g)
    {
      bresen_circle(100,450,100,g);
      bresen_circle(325,450,100,g);
      bresen_circle(550,450,100,g);
      bresen_circle(212,575,100,g);
      bresen_circle(437,575,100,g);
      
      bresen_circle(400,200,150,g);
      bresen_circle(340,150,25,g);
      bresen_circle(460,150,25,g);
      g.setColor(Color.red);
      g.fillOval(385, 190, 35, 35);
      bresen_circle(400,285,35,g);
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner cin = new Scanner(System.in);  
        Circle_bresen obj = new Circle_bresen();
        obj.setTitle("circle");
        obj.setSize(800,800);
        obj.setVisible(true);
    }
    public void bresen_circle(int x1,int y1,int r,Graphics gl){
        float d = 3-2*r;
        int x=0,y=r;
        do{
        gl.setColor(Color.red);
        gl.fillOval(x1+x, y1+y, 3, 3);
        gl.setColor(Color.BLUE);
        gl.fillOval(x1+x, y1-y, 3, 3);
        gl.setColor(Color.GREEN);
        gl.fillOval(x1-x, y1+y, 3, 3);
        gl.setColor(Color.YELLOW);
        gl.fillOval(x1-x, y1-y, 3, 3);
        gl.setColor(Color.CYAN);
        gl.fillOval(x1+y, y1+x, 3, 3);
        gl.setColor(Color.magenta);
        gl.fillOval(x1+y, y1-x, 3, 3);
        gl.setColor(Color.black);
        gl.fillOval(x1-y, y1+x, 3, 3);
        gl.setColor(Color.LIGHT_GRAY);
        gl.fillOval(x1-y, y1-x, 3, 3);
         if(d<0)
            d=d+4*x+6;
        else{
            d= d+4*(x-y)+10;
            y=y-1;
        }
        x=x+1;
        try 
         {
             Thread.sleep(15);
         } 
         catch(Throwable e) 
         {
         System.out.println(e.getMessage()); 
         }
       }while(x<y);
     }
}
