<script lang="ts">

</script>

<template>

  <div class="container1">
    <h1 class="title">Test CV</h1>
  </div>

  <body class="container2">
    <div class="mainText">
      <img class="stuff" src="./assets/sometimes.jpg" alt="picture of self"></img>
      <h3 class="stuff">pluh</h3>
    </div>
    <div class="actualbody" >
      <h1 class>qualities/qualification</h1>
    </div>
  </body>
  <footer class="container3">

  </footer>
</template>

<style>
.container1 {
  display: flex;
  justify-content: center;
  align-items: center;
  box-shadow: 0 4px 20px rgba(0, 0, 0, 0.2);
  transition: transform 0.3s;
  border-radius: 50px;
}

.container2,
.mainText {
  display: grid;
  justify-content: center;
  align-items: center;
  box-shadow: 0 4px 20px rgba(0, 0, 0, 0.2);
  transition: transform 0.3s;
  border-radius: 50px;
  margin-top: 30px;
  margin-left: 575px;
  margin-right: 550px;

}

.stuff {
  margin-left: 50px;
}

img {
  border-radius: 15px;
  width: 100px;
}
</style>