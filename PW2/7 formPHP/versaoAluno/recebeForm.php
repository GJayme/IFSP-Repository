<?php
include("util.php");

debug($_POST);

$camposNaoPreenchidos = "";

if($_POST['firstname']=='') {
  $camposNaoPreenchidos.='Nome;';
}
if($_POST['lastname']=='') {
  $camposNaoPreenchidos.='Sobrenome;';
}
if($_POST['country']=='NULL') {
  $camposNaoPreenchidos.='País;';
}
if($_POST['email']=='') {
  $camposNaoPreenchidos.='E-mail;';
}
if($_POST['senha']=='') {
  $camposNaoPreenchidos.='Senha;';
}
if($_POST['telefone']=='') {
  $camposNaoPreenchidos.='Telefone;';
}
if(!isset($_POST['cursos'])) {
  $camposNaoPreenchidos.='Cursos;';
}

echo $camposNaoPreenchidos;

if($camposNaoPreenchidos==""){
  header("Location:index.php?sucesso=true");
} else {
   header("Location:index.php?msg={$camposNaoPreenchidos}");
}