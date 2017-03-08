------------------------- Assignment #1 -------------------------
Thomas Nguyen
COEN 160 (Object Oriented Analysis, Design, and Programming)
Professor Mikkilineni

------------------------- Tools -------------------------
java version "1.8.0_111"
Java(TM) SE Runtime Environment (build 1.8.0_111-b14)
Java HotSpot(TM) 64-Bit Server VM (build 25.111-b14, mixed mode)
IDE: Eclipse Neon.2

------------------------- Question Response -------------------------
1) The above 2 methods are to be written as static methods.
   Do you see any reason to define them as instance methods, instead?
   Give your reasons as to why you think they should be instance (or static
   method).

I think that we should only create non-static classes when we know that we want
the user to create instances of our class. And users should only be creating
instances of our class when our class represents the design aspects of a
specific object.

Because the methods in MyUtil are primarily methods used for a specific function
and not so much for a specific design, I think that they should remain static.
