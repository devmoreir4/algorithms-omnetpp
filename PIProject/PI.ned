simple PINode
{
    parameters:
        @display("i=device/router,,0");
    gates:
        input in[];
        output out[];
}

network PI
{
    parameters:
        int numNodes;
        @display("bgb=156,144");
    submodules:
        node[numNodes]: PINode;
    connections allowunconnected:
        // node[0]
        node[0].out++ --> node[1].in++;
        node[1].out++ --> node[0].in++;

        node[0].out++ --> node[2].in++;
        node[2].out++ --> node[0].in++;

        // node[1]
        node[1].out++ --> node[3].in++;
        node[3].out++ --> node[1].in++;

        node[1].out++ --> node[4].in++;
        node[4].out++ --> node[1].in++;

        // node[2]
        node[2].out++ --> node[5].in++;
        node[5].out++ --> node[2].in++;

        node[2].out++ --> node[6].in++;
        node[6].out++ --> node[2].in++;
}
