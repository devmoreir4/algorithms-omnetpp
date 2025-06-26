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

package conectividade;

import ned.IdealChannel;


network Net
{
    @display("bgb=814,361");
    submodules:
        node1: Node {
            @display("p=360,100");
        }
        node2: Node {
            @display("p=264,198");
        }
        node3: Node {
            @display("p=169,128");
        }
        node4: Node {
            @display("p=169,269");
        }
        node5: Node {
            @display("p=480,204");
        }
        node6: Node {
            @display("p=586,139");
        }
        node7: Node {


            @display("p=586,292");
        }
    connections:
        node1.out++ --> IdealChannel --> node2.in++;
        node2.out++ --> IdealChannel --> node1.in++;
        node2.out++ --> IdealChannel --> node3.in++;
        node3.out++ --> IdealChannel --> node2.in++;
        node2.out++ --> IdealChannel --> node4.in++;
        node4.out++ --> IdealChannel --> node2.in++;
        node1.out++ --> IdealChannel --> node5.in++;
        node5.out++ --> IdealChannel --> node1.in++;
        node5.out++ --> IdealChannel --> node6.in++;
        node6.out++ --> IdealChannel --> node5.in++;
        node5.out++ --> IdealChannel --> node7.in++;
        node7.out++ --> IdealChannel --> node5.in++;
}
