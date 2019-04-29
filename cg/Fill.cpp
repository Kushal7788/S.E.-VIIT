#include<stdio.h> 
#include<graphics.h> 
#include<iostream> 
using namespace std; 
void draw_poly(int x[], int y[]) 
{ 
for(int i =0;i<4;i++) 
{ 
if(i+1 !=4) 
	line(x[i],y[i],x[i+1],y[i+1]); 
else 
	line(x[i],y[i],x[0],y[0]); 
} 
} 

void scale(int x[], int y[], float sx, float sy) 
{ 
draw_poly(x,y); 

int *cx = new int[4]; 
int *cy = new int[4]; 

for(int i =0;i<4;i++) 
{ 
cx[i] = x[i] *sx; 
cy[i] = y[i] *sy; 
} 

draw_poly(cx,cy); 
} 
   
void translate(int x[], int y[], int tx, int ty) 
{ 
draw_poly(x,y); 
int *cx = new int[4]; 
int *cy = new int[4]; 
for(int i=0;i<4;i++) 
{ 
cx[i] = x[i] + tx; 
cy[i] = y[i] + ty; 
} 
draw_poly(cx,cy); 
} 

void input_poly(int v, int x[], int y[]) 
{ 
for(int i=0;i<v;i++) 
{ 
	cout<<"Enter coordinate "<<i+1<<" (x,y) : "; 
	cin>>x[i]>>y[i]; 
} 
} 

int main() 
{ 
int v; 

cout<<"1. Traslation\n"; 
cout<<"2. Scaling\n"; 
cout<<"3. Rotation.\n"; 
cout<<"Enter a choice : "; 
int choice; 
cin>>choice; 
int gd, gm; 
detectgraph(&gd, &gm); 
initgraph(&gd, &gm,NULL); 
if(choice == 1) 
{ 
	cout<<"Enter the number of vertices : "; 
	cin>>v; 
	int *x = new int[v]; 
	int *y= new int[v]; 
	input_poly(v,x,y); 
	cout<<"Enter the x and y translation : ";	 
	int tx, ty; 
	cin>>tx>>ty; 
	translate(x,y,tx,ty); 
} 
else if(choice == 2) 
{ 
	cout<<"Enter the number of vertices : "; 
	cin>>v; 
	int *x = new int[v]; 
	int *y= new int[v]; 
	input_poly(v,x,y); 
	cout<<"Enter the x and y translation : ";	 
	float sx, sy; 
	cin>>sx>>sy; 
	scale(x, y, sx,sy); 
} 
else if(choice ==3) 
{ 
	int start_x, start_y,end_x,end_y,degree; 
	cout<<"Enter the starting coordinates (x,y): "; 
	cin>>start_x>>start_y; 
	cout<<"Enter the end coordinates (x,y): "; 
	cin>>end_x>>end_y; 
	cout<<"Enter the rotation angle (in degree) : "; 
	cin>>degree; 
	line(start_x, start_y,end_x,end_y); 

	float radian = 180 * (M_PI/180); 
	int nx = (end_x*cos(radian)) - (end_y*sin(radian)); 
	int ny = (end_x*sin(radian)) + (end_y*cos(radian)); 

	line(start_x, start_y,nx,ny); 
} 
else 
	cout<<"Invalid choice.\n"; 
getch(); 

return 0; 
} 
