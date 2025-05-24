from django.shortcuts import render, redirect
from .models import Cliente
from .forms import ClienteForm

def lista_clientes(request):
    busqueda = request.GET.get("buscar", "")
    if busqueda:
        clientes = Cliente.objects.filter(nombre__icontains=busqueda)
    else:
        clientes = Cliente.objects.all()
    return render(request, 'clientes/lista.html', {'clientes': clientes, 'buscar': busqueda})

def nuevo_cliente(request):
    if request.method == 'POST':
        form = ClienteForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('lista_clientes')
    else:
        form = ClienteForm()
    return render(request, 'clientes/nuevo.html', {'form': form})
