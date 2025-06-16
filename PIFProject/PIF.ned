simple PIFNode
{
    parameters:
        @display("i=device/router");
    gates:
        input in[];
        output out[];
}

network PIF
{
    parameters:
        int numNodes;
        @display("bgb=348,163");
    submodules:
        node[numNodes]: PIFNode;
    connections allowunconnected:
        for i=0..numNodes-2 {
            node[i].out++ --> node[i+1].in++;
            node[i+1].out++ --> node[i].in++;
        }

        node[1].out++ --> node[3].in++;
        node[3].out++ --> node[1].in++;

        node[2].out++ --> node[4].in++;
        node[4].out++ --> node[2].in++;

}
