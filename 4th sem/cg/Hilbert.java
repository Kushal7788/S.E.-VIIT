package javaapplication1;
import java.awt.*;
import static java.awt.Color.black;
import static java.awt.Color.red;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import java.applet.*;

public class Hilbert extends Applet {
    private SimpleGraphics sg=null;
    private int dist0=1024, dist=dist0;

    public void init() {
        dist0 = 1024;
        resize ( dist0, dist0 );
        sg = new SimpleGraphics(getGraphics());
    }

    public void paint(Graphics g) {
        int level=5;
        dist=dist0;
        for (int i=level;i>0;i--) dist /= 2;
        sg.goToXY ( dist/2, dist/2 );
        HilbertA(level); // start recursion
    }

    private void HilbertA (int level) {
        if (level > 0) {
            HilbertB(level-1);    sg.lineRel(0,dist);
            HilbertA(level-1);    sg.lineRel(dist,0);
            HilbertA(level-1);    sg.lineRel(0,-dist);
            HilbertC(level-1);
        }
    }

    private void HilbertB (int level) {
        if (level > 0) {
            HilbertA(level-1);    sg.lineRel(dist,0);
            HilbertB(level-1);    sg.lineRel(0,dist);
            HilbertB(level-1);    sg.lineRel(-dist,0);
            HilbertD(level-1);
        }
    }

    private void HilbertC (int level) {
        if (level > 0) {
            HilbertD(level-1);    sg.lineRel(-dist,0);
            HilbertC(level-1);    sg.lineRel(0,-dist);
            HilbertC(level-1);    sg.lineRel(dist,0);
            HilbertA(level-1);
        }
    }

    private void HilbertD (int level) {
        if (level > 0) {
            HilbertC(level-1);    sg.lineRel(0,-dist);
            HilbertD(level-1);    sg.lineRel(-dist,0);
            HilbertD(level-1);    sg.lineRel(0,dist);
            HilbertB(level-1);
        }
    }
}

class SimpleGraphics 
{
    private Graphics g = null;
    private int x = 0, y = 0;

    public SimpleGraphics(Graphics g) { this.g = g; }
    public void goToXY(int x, int y) { this.x = x;   this.y = y; }

    public void lineRel(int deltaX, int deltaY) {
        g.drawLine ( x, y, x+deltaX, y+deltaY );
        x += deltaX;    y += deltaY;
    }
}
