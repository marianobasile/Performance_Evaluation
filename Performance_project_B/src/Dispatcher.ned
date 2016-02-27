//
// Dispatcher --> forward the customers to the shortest queue
// 

package performance_project_b;

simple Dispatcher
{
    parameters:
        int nd;
    gates:
        input dispatcherIn;
        
        output dispatcherOut[nd];
        
        input dispatcherServiceIn[nd];
}
