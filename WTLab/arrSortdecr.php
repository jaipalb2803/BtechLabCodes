
<?php
   
  $a=array(10,20,30,40,50);
  $b=array(60,70,80,90,99);

  $merge=array_merge($a,$b);
  rsort($merge);
  print_r($merge);
?>