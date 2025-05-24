from django.urls import path
from . import views

urlpatterns = [
    path('', views.lista_clientes, name='lista_clientes'),
    path('nuevo/', views.nuevo_cliente, name='nuevo_cliente'),
]
