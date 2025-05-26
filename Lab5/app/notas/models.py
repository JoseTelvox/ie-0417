from django.db import models

class Nota(models.Model):
    titulo = models.CharField(max_length=200)
    contenido = models.TextField()
    creada = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.titulo 