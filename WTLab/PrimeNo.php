
<?php
    function Prime($n){
         echo"Prime number between 1-50<br>";
         for($i=2;$i<=$n;$i++)
         {
            $flag=0;
            for($j=2;$j<=sqrt($i);$j++)
            {
                 if($i%$j==0)
                   $flag=1;
            }
            if($flag==0)
              echo"$i &nbsp";
         }
    }    
    $n=50;
    Prime($n);
?>