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

package distancias;

import ned.IdealChannel;


network Graph
{
    @display("bgb=652,361");
    submodules:
        node1: Node {
            @display("p=161,184");
        }
        node2: Node {
            @display("p=236,70");
        }
        node3: Node {
            @display("p=236,295");
        }
        node4: Node {
            @display("p=422,70");
        }
        node5: Node {
            @display("p=422,295");
        }
        node6: Node {
            @display("p=322,184");
        }
        node7: Node {
            @display("p=485,184");
        }
    connections:
        node1.edges++ <--> IdealChannel <--> node2.edges++;
        node1.edges++ <--> IdealChannel <--> node3.edges++;
        node2.edges++ <--> IdealChannel <--> node6.edges++;
        node3.edges++ <--> IdealChannel <--> node6.edges++;
        node2.edges++ <--> IdealChannel <--> node4.edges++;
        node5.edges++ <--> IdealChannel <--> node7.edges++;
        node4.edges++ <--> IdealChannel <--> node7.edges++;
        node6.edges++ <--> IdealChannel <--> node4.edges++;
        node5.edges++ <--> IdealChannel <--> node6.edges++;
        node5.edges++ <--> IdealChannel <--> node3.edges++;
}
