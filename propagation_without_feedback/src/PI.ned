//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package propagation_without_feedback;

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
        @display("bgb=222.9,119.5");
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
