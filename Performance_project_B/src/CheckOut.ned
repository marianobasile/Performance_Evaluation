//
// Compound module queue and till
// 

package performance_project_b;

module CheckOut
{    
    gates:
        input checkoutIn;
        
        output checkoutServiceOut;
        
    submodules:
        q : Queue;
        t : Till;

	connections:
	    checkoutIn	-->	q.queueIn;
	    q.queueOut 	--> t.tillIn;
	    
	    t.tillServiceOut	-->		q.queueServiceIn;
	    q.queueServiceOut 	-->		checkoutServiceOut; 
}
