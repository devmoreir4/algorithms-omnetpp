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

package propagation_with_feedback;

//
// TODO auto-generated type
//
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