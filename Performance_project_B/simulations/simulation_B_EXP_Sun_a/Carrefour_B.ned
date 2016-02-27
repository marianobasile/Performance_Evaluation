//
// 
// 

package simulation_B_EXP_Sun_a;

import performance_project_b.*;

network Carrefour_B
{
    parameters:
        int N = default(5);
            
        @signal[startBeingServed];
        @statistic[queueingTime](source="startBeingServed"; record=vector,mean;);
        
        @signal[leaveSystem];
        @statistic[responseTime](source="leaveSystem"; record=vector,mean;);
        
    submodules:
        a 		: Aisles{ n=N; };
        c[N] 	: CheckOut;
    
    connections:
        for i=0..N-1{
        	a.aislesOut[i] --> c[i].checkoutIn;
        	
        	c[i].checkoutServiceOut --> a.aislesServiceIn[i]; 
        }
}
