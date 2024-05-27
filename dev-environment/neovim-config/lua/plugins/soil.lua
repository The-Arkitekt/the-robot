return 
{
  "javiorfo/nvim-soil",
  lazy = true,
  ft   = "plantuml",
  dependencies = {
    "javiorfo/nvim-nyctophilia"
  },
  config = function()
    vim.keymap.set('n', '<C-n>', ':Neotree filesystem reveal left<CR>', {})
  end
}
