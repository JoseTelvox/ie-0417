
# Learning Git Branching

**Learning Git Branching** es una plataforma dedicada a la enseñanza de Git. Su objetivo es instruir al usuario en el correcto manejo de un sistema de control de versiones, lo cual permite desarrollar, rastrear y fusionar cambios en proyectos de software de manera eficiente. A nivel industrial, Git es un sistema ampliamente utilizado, por lo que es valioso comprenderlo en detalle.

## Temas Abordados

### Manejo del Main y Versiones Remotas
Se introduce el concepto de **Branch**, una herramienta que permite a los desarrolladores separar el trabajo en proceso del proyecto principal.

### Concepto de HEAD
Otro concepto interesante que se aprende mientras se utiliza la plataforma es **HEAD**. Este se refiere al commit en el que está posicionado el repositorio en ese momento. El estado **HEAD detach** se refiere a cuando el puntero HEAD no está apuntando al último commit, lo cual es útil para volver a un commit anterior en caso de conflictos con el commit actual.

### Comando Cherry Pick
De la misma forma, se enseña el comando **Cherry pick**, que permite elegir una confirmación de una rama y aplicarla a otra. Esto le permite a los desarrolladores traer el contenido de commits de una Branch a otra sin tener que hacer un merge o un rebase.

### Repositorios Remotos
También se mencionan los repositorios remotos para un mejor entendimiento de las versiones que se están manipulando. Esto es parte del manejo de versiones distribuido que caracteriza el diseño de software en la actualidad. Por lo tanto, es necesario comprender los comandos **pull** y **push**. 

- **Git pull** se utiliza para buscar e integrar cambios de un repositorio remoto, agregándolos a la Branch que se está utilizando en el repositorio local.
- **Git push** se utiliza para subir los cambios creados en el repositorio local al repositorio remoto.

## Comandos Más Utilizados

- `git checkout`
- `git checkout HEAD~4`
- `git branch -f main HEAD~3`
- `git revert HEAD`
- `git reset HEAD~1`
- `git commit`
- `git merge`
- `git push`
- `git pull`
- `git rebase main`
- `git push origin main`
- `git pull origin main`
- `git pull origin main:foo`
- `git push origin main^:foo`
- `git push origin foo:main`
- `git push origin foo^:main`
- `git push origin main:newBranch`
- `git pull origin c3:foo`
- `git pull origin c2:side`

## Anexo

