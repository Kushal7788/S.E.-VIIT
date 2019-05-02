/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



package javaapplication1;
import java.awt.*;
import javax.swing.*;
import java.lang.*;
import java.util.*;

/**
 *
 * @author kushal
 */
public class trans extends JFrame {
    public void paint (Graphics g)
    {
        g.drawLine(350, 0, 350, 700);
        g.drawLine(0, 350, 700, 350);
        scale(g);
    }
        public static void main(String[] args) {
        // TODO code application logic here
        trans obj = new trans();
        obj.setTitle("hello");
        obj.setSize(700,700);
        obj.setVisible(true);
    }
        public void transform(Graphics g)
        {
            int tx = 100,ty = 100;
            int[][] arr = new int[3][3];
            int[][] ans = new int[3][3];
            int[][] mult = new int[3][3];
            mult[0][0]=mult[1][1]=mult[2][2]=1;
            g.drawLine(350, 300, 400, 350);
            g.drawLine(400, 350, 450, 300);
            g.drawLine(450,300 , 350, 300);
            
            arr[0][0]=0;
            arr[0][1]=50;
            arr[1][0]=50;
            arr[1][1]=0;
            arr[2][0]=100;
            arr[2][1]=50;
            arr[0][2]=arr[1][2]=arr[2][2]=1;
            mult[1][0]=mult[1][2]=mult[0][1]=mult[0][2]=mult[2][0]=mult[2][1]=0;
            mult[2][0]=tx;
            mult[2][1]=ty;
            
            for(int i=0;i<3;i++)
            {
                for (int j=0;j<3;j++)
                {
                    ans[i][j] = 0;
                    for(int k=0;k<3;k++)
                    {
                        ans[i][j]+= arr[i][k]*mult[k][j];   
                    }
                    System.out.print(ans[i][j]+" yy ");
                }        
            
            }
            
            int x,y,x1,y1,x2,y2;
            x=ans[0][0];
            y=ans[0][1];
            x1= ans[1][0];
            y1=ans[1][1];
            x2=ans[2][0];
            y2 = ans[2][1];
            x1=x1+350;
            y1=350-y1;
            x= x + 350;
            y= 350 - y;
            x2=x2+350;
            y2=350-y2;
            
            g.setColor(Color.red);
            g.drawLine(x, y, x1, y1);
            g.drawLine(x1, y1, x2, y2);
            g.drawLine(x, y, x2, y2);
            
            
            
//
        }
         public void scale(Graphics g)
        {
            int tx = 2,ty = 2;
            int[][] arr = new int[3][3];
            int[][] ans = new int[3][3];
            int[][] mult = new int[3][3];
            g.drawLine(350, 300, 400, 350);
            g.drawLine(400, 350, 450, 300);
            g.drawLine(450,300 , 350, 300);
            
            arr[0][0]=0;
            arr[0][1]=50;
            arr[1][0]=50;
            arr[1][1]=0;
            arr[2][0]=100;
            arr[2][1]=50;
            arr[0][2]=arr[1][2]=arr[2][2]=1;
            mult[1][0]=mult[1][2]=mult[0][1]=mult[0][2]=mult[2][0]=mult[2][1]=0;
            mult[0][0]=tx;
            mult[1][1]=ty;
            mult[2][2]=1;
            
            for(int i=0;i<3;i++)
            {
                for (int j=0;j<3;j++)
                {
                    ans[i][j] = 0;
                    for(int k=0;k<3;k++)
                    {
                        ans[i][j]+= arr[i][k]*mult[k][j];   
                    }
                    System.out.print(ans[i][j]+" yy ");
                }        
            
            }
            
            int x,y,x1,y1,x2,y2;
            x=ans[0][0];
            y=ans[0][1];
            x1= ans[1][0];
            y1=ans[1][1];
            x2=ans[2][0];
            y2 = ans[2][1];
            x1=x1+350;
            y1=350-y1;
            x= x + 350;
            y= 350 - y;
            x2=x2+350;
            y2=350-y2;
            
            g.setColor(Color.red);
            g.drawLine(x, y, x1, y1);
            g.drawLine(x1, y1, x2, y2);
            g.drawLine(x, y, x2, y2);
            
            
            
//
        }
}
