<?php
session_start();

function debug($param){
  echo '<pre>';
  print_r($param);
  echo'</pre>';
}

// Limpa a variável!!
unset($_SESSION['teste2']);

// Limpa sessão:
session_unset();

// Deleta o arquivo do HD:
session_destroy();

debug($_SESSION);
