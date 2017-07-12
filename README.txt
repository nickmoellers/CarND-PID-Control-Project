In this project, I implemented a simple PID as demonstrated by Sebastian in Python during the lesson.

First, a general description of a PID. The P term represents the error - and typically we multiply that error
by a negative constant to correct for the error. However, when this is done, we will get oscillations as we
'overshoot' the ground truth. So - in order to correct for the overshooting, we implement a D, or differential
term to compensate. Basically, all we do here is calculate the difference between the previous and next error, 
multiply that by some constant and add it bat to the P term. This will reduce oscillations. Finally, we
have an I term. I is the integral, or sum, of the previous calculations. This is issued to compensate
for some possible systematic bias - which is common if a mechanic misaligns our tires, but is actually
quite improbable in our computer simulation.

The description above is implemented in the functions UpdateError() and Steer(). Update error calculates the
error. Steer() multiples each error by its respective constant to acheive return the desired steering value.

Then, all that needs to be done in main.cpp is initialize the constants, then call the update error and
steer functions to calculate the steering values as errors come in.

But the most important part is the tuning of the parameters. First, we start by setting every parameter to 0.
Naturally, that gives us a steering angle of 0. Then, we can set the P parameter to 0.5. Now, our steering
angle is directly negatively correlated to the error, so the car corrects back to the center of the lane.
But - we'll notice that the car overcorrects. It oscillates down the road - I would not want to be in that car.
So, we up the D term to 0.5. Then, the oscilattion is reduced ( but not eliminated ).

Note - my vmware to Windows setup gives me quite a bit of lag between uWS messages - so my velocity is set
quite low.
