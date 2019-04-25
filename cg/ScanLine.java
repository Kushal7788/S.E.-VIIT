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
 * @author RohitL
 */
public class ScanLine extends JFrame{
    int no_vert = 5;
    int [][] vert = new int[no_vert][4];
    double [] slope = new double [no_vert];
    Vector x_inter = new Vector();
    /**
     * @param args the command line arguments
     */
     public void delay()
    {
        try
        {
            Thread.sleep(2);
        }
        catch(Throwable e)
                {
                    System.out.println(e.getMessage());
                }
    }
    
    int in_or_out(int y,int y1,int y2)
    {
        if((y1-y)*(y2-y)>0)
            return 1;
        else
            return 0;
    }
    int ret_y1(int y,int m,int b)
    {
        int temp;
        temp = (y-b)/m;
        return temp;
    }
    
    public static void sortbyColumn(int arr[][], int col1,int col2, int col3) 
    { 
        Arrays.sort(arr, new Comparator<int[]>() { 
            
          @Override              
          public int compare(final int[] entry1,  
                             final int[] entry2) { 
  
            // To sort in descending order revert  
            // the '>' Operator 
            if (entry1[col1] < entry2[col1]) 
                return 1; 
            else if((entry1[col1] == entry2[col1])&&(entry1[col2] < entry2[col2]))
                return 1;
            else if((entry1[col1] == entry2[col1])&&(entry1[col2] == entry2[col2])&&(entry1[col3] > entry2[col3]))
                return 1;
            else
                return -1; 
          } 
        });  // End of function call sort(). 
    }
    
    double inv_slope(int x1,int y1, int x2, int y2)
    {
        return Math.round(((double)x2-(double)x1)/((double)y2-(double)y1)*100.0)/100.0;
        //return m;
    }
    
    void arrange()
    {
        int i;
        for(i=0;i<no_vert;i++)
        {
            if(vert[i][1]<vert[i][3])
            {
                int temp;
                temp = vert[i][1];
                vert[i][1] = vert[i][3];
                vert[i][3] = temp;
                temp = vert[i][0];
                vert[i][0] = vert[i][2];
                vert[i][2] = temp;
            }
        }
    }
    
    public void paint(Graphics g)
    {
       /* g.setColor(Color.red);
        g.drawLine(400, 400, 700, 700);
        g.drawLine(400, 400, 100, 700);
        g.drawLine(100,700,700,700);
        
        int m1 = 1;
        int m2 = -1;
        int i;
        int temp1,temp2;
        g.setColor(Color.GREEN);
        for(i=400;i<700;i++)
        {
            temp1 = ret_y1(i,1,0);
            temp2 = ret_y1(i,-1,800);
            delay();
            g.drawLine(temp1, i, temp2, i);
        }*/
        
        
        vert[0][0] = 50;
        vert[0][1] = 50;
        vert[1][0] = 150;
        vert[1][1] = 250;
        vert[2][0] = 50;
        vert[2][1] = 450;
        vert[3][0] = 10;
        vert[3][1] = 100;
//        vert[4][0] = 100;
//        vert[4][1] = 900;
//        
//        vert[4][2] = 100;
//        vert[4][3] = 100;
        vert[0][2] = 150;
        vert[0][3] = 250;
        vert[1][2] = 50;
        vert[1][3] = 450;
        vert[2][2] = 10;
        vert[2][3] = 100;
        vert[3][2] = 50;
        vert[3][3] = 50;
        g.setColor(Color.BLUE);
        int i;
        for(i=0;i<no_vert;i++)
        {
            
        }
        arrange();
        sortbyColumn(vert, 1,3,2);
        /*System.out.println(vert[0][0]);
        System.out.println(vert[0][1]);
        System.out.println(vert[0][2]);
        System.out.println(vert[0][3]);
        double x = (double)(2/3);*/
        for(i=0;i<no_vert;i++)
        {
            g.drawLine(vert[i][0],vert[i][1],vert[i][2],vert[i][3]);
            System.out.println();
            System.out.print(" "+vert[i][0]);
            System.out.print(" "+vert[i][1]);
            System.out.print(" "+vert[i][2]);
            System.out.print(" "+vert[i][3]);
            slope[i] = inv_slope(vert[i][0],vert[i][1],vert[i][2],vert[i][3]);
            System.out.print(" "+slope[i]);
        }
        int y_max = vert[0][1];
        int y_min = vert[4][3];
        System.out.println(" "+y_max+" "+y_min );
        System.out.println();
        g.setColor(Color.GREEN);
        
        int j;
        for(i = y_max-1;i>y_min;i--)
        {
            System.out.print(" "+i);
            for(j=0;j<no_vert;j++)
            {
                //System.out.println("Hello");
                
                if(i<=vert[j][1]&&i>vert[j][3])
                {
                    int xinet;
                    xinet = (int)((slope[j]*(i-vert[j][1]))+vert[j][0]);
                    System.out.print(" "+xinet);
                    //System.out.println("Hello");
                    x_inter.add(xinet);
                }
                
            }
            System.out.println();
            Collections.sort(x_inter);
          //System.out.println(x_inter.size());
            
            int k;
            if(!x_inter.isEmpty())
            {
            for(k=0;k<1;k++)
            {
                g.drawLine((int)x_inter.get(k),i ,(int) x_inter.get(k+1), i);
                delay();
            }
            x_inter.clear();
            }
        }
        
        
    }
    
    
    public static void main(String[] args) {
        ScanLine obj = new ScanLine();

        obj.setTitle("Scan Fill");
        obj.setSize(300, 500);
        obj.setVisible(true);
        //obj.setBackground(Color.GRAY);
    }
    
}