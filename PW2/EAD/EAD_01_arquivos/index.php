<html>
   <head>
      <title>Arquivo com PHP</title>
   </head>
   <body>
      <?php
         function debug($param){
            echo "<pre>";
            print_r($param);
            echo "</pre>";
         }

         $totalCompu;
         $totalMed;   
         $totalFisica;
         $totalFisio;
         $totalSoft;
         $totalIA;
         $totalQuim;
         $totalLetras;
         $totalRH;
         $totalComp;

         $arquivoFunncionarios = fopen("./arquivos/funcionario.csv", "r");
         $arquivoDepartamenntos = fopen("./arquivos/departamento.csv", "r");
         
         if( $arquivoFunncionarios == false ) {
            echo ("Erro ao abrir o arquivo de funcionários!");
            exit();
         }
         
         $filesize = filesize("./arquivos/funcionario.csv");
         echo ( "Tamanho do arquivo : $filesize bytes" );

         $funcionarios = [];
         while (($linha = fgets($arquivoFunncionarios)) !== FALSE) {
            $funcionario = [];
            $linha=str_replace('"', '', $linha);
            $linhaExplodida = explode(';',$linha);

            //Cria um array associativo para o funcionario atual
            $funcionario["id"]=$linhaExplodida[0];
            $funcionario["nome"]=$linhaExplodida[1];
            $funcionario["salario"]=$linhaExplodida[6];
            $funcionario["idDepartamento"]=$linhaExplodida[8];
            array_push($funcionarios, $funcionario);
         }
         fclose($arquivoFunncionarios);

         $numFuncionarios = count($funcionarios);
      
         if($arquivoDepartamenntos == false ) {
            echo ("Erro ao abrir o arquivo de departamentos!");
            exit();
         }

         $departamentos = [];
         while (($linha = fgets($arquivoDepartamenntos)) !== FALSE) {
            $departamento = [];
            $linha = str_replace('"', '', $linha);
            $linhaExplodida = explode(';', $linha);

            $departamento["id"] = $linhaExplodida[0];
            $departamento["nome"] = $linhaExplodida[1];

            array_push($departamentos, $departamento);
         }
         fclose($arquivoDepartamenntos);

         debug($departamentos);

         for($i = 1; $i < count($funcionarios); $i++) {
            for($j = 1; $j < count($departamentos); $j++) {
               if(intval(($funcionarios[$i]["idDepartamento"])) == ($departamentos[$j]["id"])) {
                  $funcionarios[$i]["Nome Departamento"] = $departamentos[$j]["nome"];
               }
            }
         }
         
         for($i = 1; $i < count($funcionarios); $i++) {
            if($funcionarios[$i]["Nome Departamento"] == "Dep Computação") {
               $totalCompu .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Medicina") {
               $totalMed .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Ed. Física") {
               $totalFisica .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Fisioterapia") {
               $totalFisio .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Eng Software") {
               $totalSoft .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep IA") {
               $totalIA .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Eng Quimica") {
               $totalQuim .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Letras") {
               $totalLetras .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep RH") {
               $totalRH .= $funcionarios[$i]["salario"];
            }
            if($funcionarios[$i]["Nome Departamento"] == "Dep Compras") {
               $totalComp .= $funcionarios[$i]["salario"];
            }
         }

         $mediaCompu = $totalCompu/$numFuncionarios;
         $mediaMed = $totalMed/$numFuncionarios;
         $mediaFisica = $totalFisica/$numFuncionarios;
         $mediaFisio = $totalFisio/$numFuncionarios;
         $mediaSoft = $totalSoft/$numFuncionarios;
         $mediaIA = $totalIA/$numFuncionarios;
         $mediaQuim = $totalQuim/$numFuncionarios;
         $mediaLetras = $totalLetras/$numFuncionarios;
         $mediaRH = $totalRH/$numFuncionarios;
         $mediaComp = $totalComp/$numFuncionarios;

         for($j = 1; $j < count($departamentos); $j++) {
            if($departamentos[$j]["nome"] == "Dep Computação") {
               $departamentos[$j]["Média Salarial"] = $mediaCompu;
            }
            if($departamentos[$j]["nome"] == "Dep Medicina") {
               $departamentos[$j]["Média Salarial"] = $mediaMed;
            }
            if($departamentos[$j]["nome"] == "Dep Ed. Física") {
               $departamentos[$j]["Média Salarial"] = $mediaFisica;
            }
            if($departamentos[$j]["nome"] == "Dep Fisioterapia") {
               $departamentos[$j]["Média Salarial"] = $mediaFisio;
            }
            if($departamentos[$j]["nome"] == "Dep Eng Software") {
               $departamentos[$j]["Média Salarial"] = $mediaSoft;
            }
            if($departamentos[$j]["nome"] == "Dep IA") {
               $departamentos[$j]["Média Salarial"] = $mediaIA;
            }
            if($departamentos[$j]["nome"] == "Dep Eng Quimica") {
               $departamentos[$j]["Média Salarial"] = $mediaQuim;
            }
            if($departamentos[$j]["nome"] == "Dep Letras") {
               $departamentos[$j]["Média Salarial"] = $mediaLetras;
            }
            if($departamentos[$j]["nome"] == "Dep RH") {
               $departamentos[$j]["Média Salarial"] = $mediaRH;
            }
            if($departamentos[$j]["nome"] == "Dep Compras") {
               $departamentos[$j]["Média Salarial"] = $mediaComp;
            }
         }
         debug($departamentos);

         //Transforma em JSON e salva no arquivo.
         $departamentos = json_encode($departamentos);
         
         $filename = "./json/funcionarios.json";
         $file = fopen( $filename, "w" );
         
         if( $file == false ) {
            echo ( "Erro ao abrir o arquivo" );
            exit();
         }
         fwrite( $file, $departamentos);
         fclose( $file );
      ?>
   </body>
</html>