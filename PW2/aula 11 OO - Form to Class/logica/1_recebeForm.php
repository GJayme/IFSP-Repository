<?php
echo "<hr>";
echo "<pre>";
print_r($_POST);
echo "</pre>";

include("ModelCliente.php");

$cliente = new ModelCliente();

$cliente->construtorPOST();

//echo $cliente;
echo "<br>";
//echo json_encode($cliente);

echo "<hr>";
echo "<pre>";
print_r($cliente);
echo "</pre>";

echo $cliente->getNome().'<br>';
echo $cliente->getEmail().'<br>';
echo $cliente->getSenha().'<br>';
echo $cliente;
//echo $cliente->nome;