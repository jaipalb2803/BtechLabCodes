
<?php 
  $source=fopen("source.txt","r");
  $target=fopen("target.txt","w");
  if($source==false)
    exit("Error for open");
  else
    print("source file opened<br>");
  while(!feof($source))
  {
    $line=fgets($source);
    fwrite($target,$line);
  }
  print("Data read successfully");
  fclose($source);
  fclose($target);
?>