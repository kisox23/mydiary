import emoji

def get_key(value, dictio):
    for key, val in dictio.items():
        if value == val:
            return key


def get_next_key(temp_key, dictio):
    temp = list(dictio)
    try:
        res = temp[temp.index(temp_key) + 1]
    except (ValueError, IndexError):
        res = None
    return res

def get_previous_key(temp_key, dictio):
    temp = list(dictio)
    try:
        res = temp[temp.index(temp_key) - 1]
    except (ValueError, IndexError):
        res = None
    return res

def deEmojify(text):
    return emoji.get_emoji_regexp().sub(u'', text)
