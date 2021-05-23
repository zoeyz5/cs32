#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

int main() {
    WordCount wc;
    wc.incrWordCount("ApPles");
    wc.incrWordCount("'appl-e123's'");
    wc.incrWordCount("ApPles123");
    wc.incrWordCount("Banana");
    wc.incrWordCount("Cat");
    wc.incrWordCount("Ca-t''");

    assertEquals("monkeys", WordCount::makeValidWord("12mOnkEYs-$").c_str(),"makeValidWord function", 14);
    assertEquals("apples", WordCount::makeValidWord("ApPles123").c_str(),"makeValidWord function", 15);
    
    assertEquals("appl-e's",WordCount::makeValidWord("'appl-e123's'").c_str(),"check if stripWord function remove the special character and hyphens and apostrophes in the beginning and at the end", 17);
    
    assertEquals(2, wc.getWordCount("ApPles"), "getWordCount function", 19);
    
    assertEquals(6,wc.getTotalWords(), "getTotalWords function", 21);
    
    assertEquals(5,wc.getNumUniqueWords(), "getUniqueWords function", 23);
    
    assertEquals(1, wc.getWordCount("Cat"), "getWordCount function", 25);
    
    wc.decrWordCount("Dog");
    assertEquals(-1, wc.decrWordCount("Dog"), "decrWordCount function", 28);
    
    wc.decrWordCount("apples");
    assertEquals(1, wc.getWordCount("apples"), "decrWordCount function", 31);
    
    wc.decrWordCount("apples");
    assertEquals(0, wc.getWordCount("apples"), "decrWordCount function", 34);
    
    wc.decrWordCount("Cat");
    assertEquals(0, wc.getWordCount("Cat"), "decrWordCount function", 37);
    
    return 0;
    
}
