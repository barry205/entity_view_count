
(function ($) {

  Drupal.behaviors.EntityVewCountHandler = {
    attach: function () {
      var element = $("#edit-options-sort-style");

      showHide(element);

      element.change(function() {
        showHide(element);
      });
    }
  };

  /**
   * Show and hide the element.
   *
   * @param element
   *  Variable which present the element on which we need to hide or show the
   *  entity type elements.
   */
  function showHide(element) {
    if (element.val() == 'default') {
      $(".form-item-options-entity-type").show();
    }
    else {
      $(".form-item-options-entity-type").hide();
    }
  }

})(jQuery);
