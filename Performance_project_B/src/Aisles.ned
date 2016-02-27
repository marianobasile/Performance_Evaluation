//
// Compount module that contains generator and dispatcher of the customers
// 

package performance_project_b;

module Aisles
{
    parameters:
        int n;
    
    gates:
        output aislesOut[n];
        
        input aislesServiceIn[n];
        
    submodules:
        g : Generator;
        d : Dispatcher{	nd=n; };
        
    connections:
        g.generatorOut --> d.dispatcherIn;
        
        for i=0..n-1{
            			d.dispatcherOut[i] 	-->	aislesOut[i];
            			
            			aislesServiceIn[i]	--> d.dispatcherServiceIn[i];
        }
        
        
            			
}
