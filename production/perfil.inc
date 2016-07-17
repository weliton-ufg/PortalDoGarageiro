<div class="container-fluid">
  <div class=" col-md-12">
    <div class="row">


      <div class="col-md-4">
        <form action="fotoPerfil.php" method="post" enctype="multipart/form-data"
        onsubmit="comprova_extensao(this.form, this.form.imagem.value);return false;">

          <div class="form-group col-md-7">
          <img alt="Bootstrap Image Preview" src="images/simboloImg.png" class="img-thumbnail" />
            <label for="exampleInputFile">Imagem</label>
            <input type="file" name="imagem" required="" />
              <p class="help-block">Escolha uma imagem para o veículo.</p>

            <input type="text" hidden="" name="idUsuario" 
            value="<?php echo $_SESSION['idUsuario']; ?>">
            <button type="submit" class="btn btn-success" onclick="">
              Salvar Foto
           </button>
        </form>

        </div>
      </div>
    </div>
  </div>
</div>