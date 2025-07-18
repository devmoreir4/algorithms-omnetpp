simple Txc3
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

//
// Same as Tictoc2.
//
network Tictoc3
{
    @display("bgb=100.4,65.9");
    submodules:
        tic: Txc3 {
            parameters:
                @display("i=,cyan;p=72.8,19.9");
        }
        toc: Txc3 {
            parameters:
                @display("i=,gold;p=24.4,46.4");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
