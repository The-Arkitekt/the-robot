return 
{
  "javiorfo/nvim-soil",
  lazy = true,
  ft   = "plantuml",
  dependencies = {
    "javiorfo/nvim-nyctophilia"
  },
  config = function()
    require('soil').setup {
      image = {
        darkmode = false,
        format   = "png",

        execute_to_open = function(img)
          return "nsxiv -b " .. img
        end
      }
    }
  end
}
