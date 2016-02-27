//
// Network that simulates the Carrefour A Scenarios
// 

package simulation_A_LN_Sat_vh;

import performance_project.*;

network Carrefour_A
{
    parameters:
        int N = default(5);
        double D @unit(s) = default(2s);
        
        @signal[startBeingServed];
        @statistic[queueingTime](source="startBeingServed"; record=vector,mean;);
        
        @signal[leaveSystem];
        @statistic[responseTime](source="leaveSystem"; record=vector,mean;);
                
    submodules:
        g 	: Generator;
        ts	: Tills{	n=N; };
        w 	: Waiters{	n=N; };
        
    connections:
        g.generatorOut 	-->	w.waitersIn;
        
        for i=0..N-1 {
            			w.waitersOut[i]	--> { delay= (i+1)*D ; } --> ts.tillsIn[i];
            			ts.tillsServiceOut[i] 	-->	 w.waitersServiceIn[i];  
        }
}
