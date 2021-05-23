#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>


int main() {
    WordCount wc;
    wc.addAllWords("-Sentence is a f/un fun  ????*:     sente%nce.");
    std::ostringstream oss;
    wc.dumpWordsSortedByWord(oss);
    
    assertEquals("sentence,2\nis,1\nfun,2\na,1\n",oss.str(),"dumpWordsSortedByWord function", 17);
    
    std::ostringstream oss2;
    wc.dumpWordsSortedByOccurence(oss2);
    assertEquals("a,1\nis,1\nfun,2\nsentence,2\n",oss2.str(),"dumpWordsSortedByWord function", 21);
     
    
    return 0;
    
}
