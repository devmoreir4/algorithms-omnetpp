simple Tic8
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

simple Toc8
{
    parameters:
        @display("i=block/process");
    gates:
        input in;
        output out;
}

network Tictoc8
{
    @display("bgb=158,124");
    submodules:
        tic: Tic8 {
            parameters:
                @display("i=,cyan;p=45,76");
        }
        toc: Toc8 {
            parameters:
                @display("i=,gold;p=108,37");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
