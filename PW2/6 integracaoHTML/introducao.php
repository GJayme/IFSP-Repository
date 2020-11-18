<?php
  function debug($param){
    echo"<pre>";
    print_r($param);
    echo"<pre>";
  }

  $nome='Gabriel';
  
  echo "<h1>Hello World! PHP".$nome."</h1>";
  echo "<h1>Hello World! PHP{$nome}</h1>";
  
  $lista=[1,2,3,4];
  // echo $lista;
  print_r($lista);
  
  $dicionario["Gabriel"]=15;
  $dicionario["Ramos"]=10;
  $dicionario["Henrique"]=8;
  echo"<hr>";

  print_r($dicionario);

  debug($dicionario);
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>
<body>
  <ul>
    <?php echo "<li>Item</li>";?>
    <?= "<li>Item</li>"?>
  </ul>

  <ul>
    <?php foreach ($dicionario as $chave => $valor): ?>
      <li> <?=$chave;?> - <?=$valor;?</li>;
    <? endforeach;?>
  </ul>
</body>
<script>
    document.write("<br> Hello Word JS")
  </script>
</html>