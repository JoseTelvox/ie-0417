from django.urls import path
from .views import lista_notas

app_name = 'notas'
urlpatterns = [
    path('', lista_notas, name='lista'),
] 