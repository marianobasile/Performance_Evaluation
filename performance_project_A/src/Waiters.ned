//
// Compound module that contains Queue + Dispatcher
// 

package performance_project;

module Waiters
{
    parameters:
        int n;
    
    gates:
        input waitersIn;
        output waitersOut[n];
        
        input waitersServiceIn[n];
        
    submodules:
        q : Queue;
        d : Dispatcher{	nd=n; };
        
	connections:
	    waitersIn	--> 	q.queueIn;
	    q.queueOut	--> 	d.dispatcherIn;
	    
	    for i=0..n-1 {
	     	   			d.dispatcherOut[i]	--> 	waitersOut[i];
	     	   			
	     	   			waitersServiceIn[i] --> 	d.dispatcherServiceIn[i];
	    }
	    
	    d.dispatcherServiceOut	-->		q.queueServiceIn;
        
}
