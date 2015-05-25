<?php 


/*
 * Implements hook_views_data().
 *
 */
 
 function youtube_activity_views_data() {
  
  
  $data['activities'] = array(
  'table' => array(
    'base' => array(
      'field' => 'id',
      'title' => 'yotube activities',
      'help' => 'id de los datos',
    ),
    'group' => 'yotutube',
  ),

  'yid' => array(
    'title' => 'ydi',
    'help' => 'Primary Key: id del video.',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  
  ),

  'type' => array(
    'title' => 'Tipo',
    'help' => 'Tipo de actividad. ej "upload"',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  ),

  'id' => array(
    'title' => 'Id Youtube',
    'help' => 'string de url youtube.',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),

    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),

  ),

  'channelId' => array(
    'title' => 'Canal',
    'help' => 'String del CHANNEL.',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),

    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),

  ),


  'title' => array(
    'title' => 'Titulo',
    'help' => 'Titulo del video.',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),

    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),

  ),
'description' => array(
    'title' => 'Descripcion',
    'help' => 'Descripcion del video.',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),

    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),

  ),

  'publishedAt' => array(
    'title' => 'Pubicado',
    'help' => 'Horario de publicacion.',
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  ),

  'json' => array(
    'title' => 'Json element',
    'help' => 'Json element .',
    'field' => array(
      'handler' => 'views_handler_field_jsondata',
      'click sortable' => FALSE,
    ),
  
  ),




  'status' => array(
    'title' => 'Publicado',
    'help' => 'si esta publicado.',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  
  ),


);

return $data;
}



/**
 * A handler to display dates as just the time if today, otherwise as time and date.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_youvideo extends views_handler_field {
 
  function option_definition() {
    $options = parent::option_definition();
    $options['view_mode'] = array('default' => 'player');

    $options['width'] = array('default' => '100%');
    $options['height'] = array('default' => '500');
    $options['autoplay'] = array('default' => '0');
   
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['view_mode']= array(
       '#type' => 'select',
       '#title' => t('view mode'),
       '#options' => array(
            'text' => 'text',
            'player' => 'player',
            'default' => 'thumb-> default',
            'mqdefault' => 'thumb-> medium',
            'hqdefault' => 'thumb -> high',
       ),
        '#default_value' => isset($this->options['view_mode']) ? $this->options['view_mode'] : 'player',
      );

    $form['width'] = array(
      '#type' => 'textfield', 
      '#title' => t('width'), 
      '#default_value' => isset($this->options['width']) ? $this->options['width'] : '100%', 
      '#size' => 60, 
      '#maxlength' => 255, 

    );

    $form['height'] = array(
      '#type' => 'textfield', 
      '#title' => t('height'), 
      '#default_value' => isset($this->options['height']) ? $this->options['height'] : '500', 
      '#size' => 60, 
      '#maxlength' => 255, 

    );
    $form['autoplay']= array(
       '#type' => 'select',
       '#title' => t('autoplay'),
       '#options' => array(
            '1' => 'yes',
            '0' => 'no',
       ),
        '#default_value' => isset($this->options['autoplay']) ? $this->options['autoplay'] : '0',
      );

  }  
     
  function render($values) {

    $element = $this->options['view_mode'];
    $value =  $values->{$this->field_alias};
    switch ($element) {

      case 'player':
        return  '<iframe id="ytplayer" type="text/html" width="'.$this->options['width'].'" height="'.$this->options['height'].'"
  src="http://www.youtube.com/embed/'. $value .'?autoplay='.$this->options['autoplay'].'"  frameborder="0"/></iframe>'
; 
        break;
      case 'default':
      case 'mddefault':
      case 'hqdefault':
        return  "<img src=\"https://i.ytimg.com/vi/{$value}/{$element}.jpg\"  width=\"{$this->options['width']}\" height=\"{$this->options['height']}\">"; 
        break;


      default:
        return  $value; 
        break;
    }
   }
}


/**
 * A handler to display dates as just the time if today, otherwise as time and date.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_jsondata extends views_handler_field {
 
  function option_definition() {
    $options = parent::option_definition();

    $options['element'] = array('default' => 'default');
   
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['element']= array(
       '#type' => 'select',
       '#title' => t('Element'),
       '#options' => array(
            'default' => 'thumb-> default',
            'medium' => 'thumb-> medium',
            'high' => 'thumb -> high',
            'player' => 'player',
       ),
        '#default_value' => isset($this->options['element']) ? $this->options['element'] : 'default',
      );

  }  
     
  function render($values) {

    $element = $this->options['element'];
    $value = json_decode( $values->{$this->field_alias});
    switch ($element) {
      case 'default':
        return  "<img src=\"{$value->snippet->thumbnails->default->url}\">"; 
      case 'medium':
        return  "<img src=\"{$value->snippet->thumbnails->medium->url}\">"; 
      case 'high':
        return  "<img src=\"{$value->snippet->thumbnails->high->url}\">"; 
        break;

      case 'player':
        return  '<iframe id="ytplayer" type="text/html" width="100%" height="500"
  src="http://www.youtube.com/embed/'. $value->contentDetails->upload->videoId.'?autoplay=0"  frameborder="0"/></iframe>'
; 
        break;

      default:
        return  "<img src=\"{$value->snippet->thumbnails->default->url}\">"; 
        break;
    }
   }
}