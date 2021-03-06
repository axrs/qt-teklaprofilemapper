TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    src \
    test \
    console

#The GUI Application relies on the `src` library
console.depends = src

#The Unit Tests relies on the `src` library
test.depends = src

#common configuration used for all sub projects
include ("defaults.pri")

DISTFILES += \
    uncrustify.cfg \
    .astylerc \
    team.md \
    readme.md
