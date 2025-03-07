
<?php
   $str="Hello Jntuhces";
   $search="Jntuhces";
   
   $len=strlen($str);
   echo"<b>Length string</b>-'$str':<b>$len</b><br>";
   $word=str_word_count($str);
   echo"<b>No.of word string</b> -'$str':<b>$word</b><br>";
   $rev=strrev($str);
   echo"<b>Reverse string</b>-'$str':<b>$rev</b><br>";
   $pos=strpos($str,$search);
   if($pos!==false)
     echo"String <b>-'$search'</b> found at <b>$pos</b> position in <b>'$str'</b><br>";
   else
     echo"String <b>'$search'</b> not found<br>";
?>