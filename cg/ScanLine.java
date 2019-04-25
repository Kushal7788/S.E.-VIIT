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
public class ScanLine extends JFrame {
     public void paint (Graphics g)
    {
       Scanl(g);     
    }
     public void Scanl(Graphics g){
         Scanner cin = new Scanner(System.in);
         g.setColor(Color.BLUE);
//        g.drawLine(100, 100, 300, 500);
//        g.drawLine(300, 500, 500, 500);
//        g.drawLine(500, 500, 100, 100);
        
        int ver = 5;
        int m1,m2;
        int[] x = new int[ver];
        int[] y = new int[ver];
        int[] m = new int[ver];
        for(int i=0;i<ver;i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
        }
        for(int i=0;i<ver;i++)
        {
            if (i == ver-1)
            {
                g.drawLine(x[i], y[i], x[0], y[0]);
            }
            else
            {
            int a=x[i],b=x[i+1],c=y[i],d=y[i+1];
            g.drawLine(a, c, b, d);
            }
        }
        m1=2;
        m2=1;
//        int yt,yma=500,ymi=100;
//        yt=yma-1;
//        while(yt>=ymi)
//        {
//            int x1,x2;
//            x1 = (yt+100)/m1;
//            x2 = (yt)/m2;
//            g.setColor(red);
//            g.drawLine(x1+1, yt, x2-1, yt);
//            yt--;
//            try 
//         {
//             Thread.sleep(15);
//         } 
//         catch(Throwable e) 
//         {
//         System.out.println(e.getMessage()); 
//         }
//        }
     }
     public static void main(String[] args) { 
        // TODO code application logic here
        ScanLine obj = new ScanLine();
        obj.setTitle("ScanLine");
        obj.setSize(1366,768);
        obj.setVisible(true);
        
    }
}
