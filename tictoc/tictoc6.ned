simple Txc6
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

network Tictoc6
{
    @display("bgb=174,130");
    submodules:
        tic: Txc6 {
            parameters:
                @display("i=,cyan;p=42,79");
        }
        toc: Txc6 {
            parameters:
                @display("i=,gold;p=118,40");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
