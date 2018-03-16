# cpp-textgame
Implementation of the C++ text adventure tutorial at https://cplussplussatplay.blogspot.ca/2012/11/text-adventure-games-c-part-1.html

I decided to try something simple without a lot of graphics as a little project X3 I'm following the tutorial here, but the author was trying to challenge himself not to look up a bunch of stuff online. So, I'm trying to do things in a more robust and/or concise way as I go. I'm not too worried about performance since well... It's a text game!

Anyway, I intend to get through the tutorial, then clean this up, split it into more than just the one big file, and try to make a little game of my own with it X3 Hit me up if you know some more good stuff to look at to learn!

## Compilation Notes

I made this a Visual Studio (2017) project, but as of the current commit you should just be able to schlunk all the files into a folder and compile it for whatever platform if you don't use VS; I don't have any references to the Windows API as of this commit except in targetver.h, which I don't include anywhere. I'd like to avoid anything platform-specific anyway, unless it turns out to be useful for saving/loading games and even then I'd like to try some conditional compilation for that.~