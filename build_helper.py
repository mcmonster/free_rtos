def decorateLibs(libs, prefix='', suffix=''):
    return decorateSource(libs, prefix, suffix)

def decorateSource(sources, prefix='', suffix = ''):
    ''' Adds the provided prefix and suffix to each source name. '''
    prefixed_sources = []

    for source in sources:
        prefixed_sources.append(prefix + source + suffix)

    return prefixed_sources
