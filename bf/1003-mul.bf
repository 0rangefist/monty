,>,                     input into c0 and c1
>                       move to c2
++++++++++              write ascii 48 to c2
++++++++++
++++++++++
++++++++++
+++++ +++

subtracting ascii 48 from user input in c0 & c1
[                       loop till c2 is 0
        <-              decrease c1 by 1
        <-              decrease c0 by 1
        >>-             decrease c2 by 1
]                       end loop

setting up the multiplication loop c2 = c0*c1
<<                      move back to c0
[                       loop till c0 is 0
        >               move to c1
        copy c1 to c2 and backup copy in c3
        [               loop till c1 is 0
                >+      increase c2 by 1
                >+      increase c3 by 1
                <<-     deacrease c1 by 1
        ]               end c1 loop

        >>              move to c3
        move backup copy from c3 back to c1
        [               loop till c3 is 0
                <<+     increase c1 by 1
                >>-     decrease c3 by 1
        ]               end c3 loop

        <<<-            decrease c0 by 1
]                       end of c0 loop

>>                      move to c2
++++++++++              add ascii 48 to c2
++++++++++
++++++++++
++++++++++
+++++ +++
.                       print answer in c2
[-]			reset c2 to 0
print newline ascii "\n" 10
+++++ +++++                     set c2 to 10
.                               print value in c2
