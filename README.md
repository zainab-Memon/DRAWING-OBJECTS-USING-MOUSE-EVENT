# DRAWING-OBJECTS-USING-MOUSE-EVENT

**Algorithms used:**

**Midpoint circle algorithm: **

We need to plot the perimeter points of a circle whose center co-ordinates and radius are given.
We use “Midpoint circle algorithm” to calculate all the perimeter points of the circle in the first octant and then print them along with other remaining 7 mirror points just by changing the sign of x and y coordinates and by replacing x as y and y as x. it is possible because circle is a symmetric. 
For any given pixel(x, y), the next pixel to be plotter is either (x+1, y) or either
 (x+1, y-1). We can decide this by these following steps. If the given circle is centered a (0, 0) and radius r and a point p(x, y), then circle
f(x, y) =x^2 +y^2 – r^2.
 If   circle f(x,y)<0, then this point is inside the circle boundary, so we will have to choose the next point (x+1,y), and if   circle f(x,y)>0  then this point is outside the circle boundary, so we will have to choose the next point (x+1,y-1). Repeat this test until x >_ y.  

**Random color generating algorithm: **

This algorithm generates random color for every object created.

**Events used: **
**Mouse events: **

Such as leftButtonDown, leftButtonUp, leftButtonStillDown... Note that different “species” of mice have different numbers of buttons, so for some kinds of mice some of these events are collapsed. Mouse events are such user interacts with program which he do by mouse buttons, by pressing down or releasing up mouse button. That button could be left or right. Different mouse buttons can perform different task, depending on programmer’s statements and requirements.

**Keyboard event:**

glutKeyboardFunc sets the keyboard callback for the current window. When a user types into the window, each key press generating an ASCII character will generate a keyboard callback. The key callback parameter is the generated ASCII character. The state of modifier keys such as Shift cannot be determined directly; their only effect will be on the returned ASCII data. The x and y callback parameters indicate the mouse location in window relative coordinates when the key was pressed. When a new window is created, no keyboard callback is initially registered, and ASCII key strokes in the window are ignored. Passing NULL to glutKeyboardFunc disables the generation of keyboard callbacks.  
During a keyboard callback, glutGetModifiers may be called to determine the state of modifier keys when the keystroke generating the callback occurred
