from django.shortcuts import render, redirect
from django.contrib import messages
from .models import Nota
from .forms import NotaForm

def lista_notas(request):
    if request.method == 'POST':
        form = NotaForm(request.POST)
        if form.is_valid():
            form.save()
            messages.success(request, 'Nota agregada exitosamente.')
            return redirect('notas:lista')
    else:
        form = NotaForm()
    
    notas = Nota.objects.order_by('-creada')
    return render(request, 'notas/lista.html', {
        'notas': notas,
        'form': form
    }) 